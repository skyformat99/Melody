//
//  melody.h
//  Melody
//
//  Created by 吴振宇 on 2017/5/15.
//  Copyright © 2017年 吴振宇——延迟任务. All rights reserved.
//

#ifndef melody_h
#define melody_h

#include <stdio.h>


#define URL_LENGTH 128;
// 想了 几种调用方式
//如果是赞soa nova的方式,调用需要ip地址、端口号、包名接口名、参数 pg:nova -h10.9.97.143 -p8050 -m=com.youzan.material.general.service.TokenService.getToken -a='{"kdtId":1,"scope":""}'
//如过是http请求 同事需要 url链接 、参数 同时需要判断是post 还是get, 
typedef  struct requestHttp{
	char* requestMethod; // post 或者get 默认get
} requestHttp;

typedef  struct requestInterface{
	char* InterfaceAddr; //
} requestInterface;

typedef struct callback{
	 int port; 				/* 端口号 */
	 char * url;            /*ip地址或者http url */
	 char * param;          /*参数 json类型 */
	 union{
		requestHttp * http; 
		requestInterface * interface;  
	} requestType ;
} callback;

typedef struct task {
    long taskId;
    char * taskName;
    callback * callback;
    int cycleNum;
} task;

typedef struct cycle{
    task * front;         /*头指针*/
    task * rear;          /*尾指针*/
    int taskCount;        /*槽的任务总数*/
} cycle  ;

/*操作 初始化一个任务槽                                                 */
/*前置条件 pq指向cycle其中一个槽的队列                                  */
/*后置条件 pq被初始化为空                                               */
void InitializeTaskSolt (cycle *pc)

/*操作 初始化队列                                                       */
/*前置条件 pq指向cycle其中一个槽的队列                                  */
/*后置条件 pq被初始化为空                                               */
void InitializeTaskSolt (cycle *pc)


/*操作 检查任务槽是否已满                                               */
/*前置条件 pq指向之前被初始化的队列                                     */
/*后置条件 如果队列为空 空返回ture,否则返回false                        */
bool addTask (task *pt cycle *pc)

/*操作   删除任务                                                       */
/*前置条件 pq指向之前被初始化的队列                                     */
/*后置条件 如果队列                        */
bool deleteTask (task *pt cycle *pc)

/*操作 查看任务槽的任务数                                               */
/*前置条件 pq指向之前被初始化的队列                                     */
/*后置条件 如果队列为空 空返回ture,否则返回false                        */
bool taskSoltCount (const cycle *pc)

/*操作 检查队列是否已满 暂时用不着                                      */
/*前置条件 pq指向之前被初始化的队列                                     */
/*后置条件 如果队列已满则返回true,否则返回false                         */
bool taskSoltIsFull (const cycle *pc)

#endif /* melody_h */
