//./csim -s 4 -E 1 -b 4 -t traces/yi.trace
//./csim -v -s 4 -E 1 -b 4 -t traces/yi.trace
#include "cachelab.h"
#include "unistd.h"
#include "getopt.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

typedef struct cacheLine{
    int valid_bit;
    int tag;
    int LRU;
}cache_line;

typedef struct cache_set{
    cache_line* cache_lines;
}cache_set;

typedef struct cache{
    int size;
    int lines;
    int line_size;
    cache_set* cache_sets;
}cache;

cache sim_cache;
char fileName[40];
int sum_hit,sum_miss,sum_eviction,curr_pc;
int opt1,h=-1,v=-1,s=-1,E=-1,b=-1,isVerbose=-1,is_Evict=0;

void init_cache_line(cache_line* new_cache_line){
    new_cache_line->LRU=0;
    new_cache_line->valid_bit=0;
}

void init_cache(){
    //printf("start init the cache\n");
    int temp=0,i=0;
    sim_cache.size=1<<s;
    sim_cache.lines=E;
    sim_cache.line_size=1<<b;
    sim_cache.cache_sets=(cache_set*)malloc(sizeof(cache_set)*(1<<s));
    for(temp=0;temp<(1<<s);temp++){
        sim_cache.cache_sets[temp].cache_lines=(cache_line*)malloc(sizeof(cache_line)*E);
        for(i=0;i<E;i++){
            init_cache_line(&sim_cache.cache_sets[temp].cache_lines[i]);
        }
    }
    //printf("init finished\n");
    return;
}

void helpMenuPrint(){
    printf("Usage: ./csim-ref [-hv] -s <num> -E <num> -b <num> -t <file>\n");
    printf("Options:\n");
    printf("-h         Print this help message.\n");
    printf("-v         Optional verbose flag.\n");
    printf("-s <num>   Number of set index bits.\n");
    printf("-E <num>   Number of lines per set.\n");
    printf("-b <num>   Number of block offset bits.\n");
    printf("-t <file>  Trace file.\n\n\n");
    printf("Examples:\n");
    printf("linux>  ./csim -s 4 -E 1 -b 4 -t traces/yi.trace\n");
    printf("linux>  ./csim -v -s 8 -E 2 -b 4 -t traces/yi.trace\n");
}

cache_line* load_cache(int tag_num,int set_num){
    cache_line* cache_set_instance=sim_cache.cache_sets[set_num].cache_lines;
    int i=0;
    cache_line* empty_line=NULL;
    for(i=0;i<E;i++){
        if(cache_set_instance[i].valid_bit==0){
            empty_line=&cache_set_instance[i];
	    break;
        }
    }
    if(empty_line){
        empty_line->valid_bit=1;
	//printf("use empty cache in set %d, E index %d\n",set_num,i);
        return empty_line;
    }
    else{
        int LRU_min=0x7fffffff,LRU_min_index=0;
	//printf("sum_evition+1\n");
	is_Evict=1;
        sum_eviction+=1;
        for(i=0;i<E;i++){
            if(cache_set_instance[i].LRU<LRU_min){
                LRU_min=cache_set_instance[i].LRU;
                LRU_min_index=i;
            }
        }
	//printf("use eviction in set %d, E index %d\n",set_num,LRU_min_index);
        return &cache_set_instance[LRU_min_index];
    }
}

void loadData(int address,int dataSize){
    //printf("start load data\n");
    int set_num=(address>>b)&((1<<s)-1);
    int tag_num=(address>>(s+b));
    cache_line* cache_set_instance=sim_cache.cache_sets[set_num].cache_lines;
    int i=0;
    cache_line* final_cache=NULL;
    bool isfind=false;
    for(i=0;i<E;i++){
        if(cache_set_instance[i].valid_bit==1&&cache_set_instance[i].tag==tag_num){
            final_cache=&cache_set_instance[i];
            isfind=true;
            break;
        }
    }
    if(isfind){
        //***********curr_PC not defined
        final_cache->LRU=curr_pc;
	if(isVerbose==1){
	    printf(" hit");
	}
        sum_hit+=1;
	//printf("hit at cache set %d, E index %d\n",set_num,tag_num);
	//printf("sum_hit +1\n");
    }
    else{
	is_Evict=0;
        cache_line* new_cache_line=load_cache(tag_num,set_num);
        new_cache_line->LRU=curr_pc;
	new_cache_line->tag=tag_num;
	if(isVerbose==1){
	    printf(" miss");
	}
	if(is_Evict&&isVerbose){
	    printf(" eviction");
	}
        sum_miss+=1;
	//printf("sum_miss +1\n");
    }
    //printf("load data finished\n");
}

void storeData(int address,int dataSize){
    //printf("start store data\n");
    loadData(address,dataSize);
    //printf("store data finished\n");
}

void modifyData(int address,int dataSize){
    //printf("start modify data\n");
    loadData(address,dataSize);
    storeData(address,dataSize);
    //printf("modify data finished\n");
}

void process_file(){
    char opt[10];
    int address,data_size;
    init_cache();
    //printf("file name is %s\n",fileName);
    FILE* tracefile=fopen(fileName,"r");
    //printf("start_processing_file\n");
    while(fscanf(tracefile,"%s %x,%d",opt,&address,&data_size)!=EOF){
        //printf("opt:%s\n",opt);
	if(isVerbose==1){
	    printf("%s %x,%d",opt,address,data_size);
	}
        if(strcmp(opt,"I")==0){
            continue;
        }
        if(strcmp(opt,"L")==0){
            //printf("L\n");
            loadData(address,data_size);
        }
        if(strcmp(opt,"S")==0){
            //printf("S\n");
            storeData(address,data_size);
        }
        if(strcmp(opt,"M")==0){           //Modify data
            //printf("M\n");
            modifyData(address,data_size);
        }
        if(isVerbose==1){
	    printf("\n");
	}
	curr_pc+=1;
    }
}

int main(int argc, char** argv)
{
    /* looping over arguments */
    while(-1 != (opt1 = getopt(argc, argv, "hvs:E:b:t:"))){
        /* determine which argument it’s processing */
        switch(opt1) {
            case 'v':
                isVerbose=1;
                break;
            case 's':
                s=atoi(optarg);
                break;
            case 'E':
                E=atoi(optarg);
                break;
            case 'b':
                b=atoi(optarg);
                break;
            case 't':
                strcpy(fileName,optarg);
                break;
            case 'h':
            default:
                helpMenuPrint();
                exit(0);
        }
    }
    process_file();
    //printf("h:%d v:%d s:%d E:%d b:%d isVerbose:%d\n",h,v,s,E,b,isVerbose);
    //printf("%s\n",fileName);
    //init_cache();
    //process_file();

    printSummary(sum_hit,sum_miss,sum_eviction);
    return 0;
}


