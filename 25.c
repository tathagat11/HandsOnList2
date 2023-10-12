/*
============================================================================
Name : 24.c
Author : Tathagata Talukdar
Description : Write a program to print a message queue's  (use msqid_ds and 
ipc_perm structures)    
a. access permission    
b. uid, gid    
c. time of last message sent and received       
d. time of last change in the message queue    
d. size of the queue    
f. number of messages in the queue     
g. maximum number of bytes allowed     
h. pid of the msgsnd and msgrcv
Date: 12th October 2023
============================================================================
*/

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

void main(void) {
    key_t key = ftok(".", 97);
    int message_QID = msgget(key, 0666 | IPC_CREAT);
    struct msqid_ds message_info;
    msgctl(message_QID, IPC_STAT, &message_info);
    struct ipc_perm perms = message_info.msg_perm;
    printf("access permission = %d\n", perms.mode);
    printf("uid = %d ", perms.uid);
    printf("gid = %d\n", perms.gid);
    printf("time of last message sent = %ld\n", message_info.msg_stime);
    printf("time of last message received = %ld\n", message_info.msg_rtime);
    printf("time of last change in the message queue = %ld\n", message_info.msg_ctime);
    printf("size of the queue = %ld\n", message_info.__msg_cbytes);
    printf("number of messages in the queue = %ld\n", message_info.msg_qnum);
    printf("maximum number of bytes allowed= %ld\n", message_info.msg_qbytes);
    printf("pid of the sender = %d\n", message_info.msg_lspid);
    printf("pid of receiver = %d\n", message_info.msg_lrpid);
}