// Room: /d/wiz/wizroom.c
// Modified by mudring

inherit ROOM;
#include <ansi.h>

int block_cmd();

string room_long();
void create ()
{
  set ("short","��ʦ������");
        set("long", (:room_long:));
/*
  set ("long", @LONG

��������ʦ�������۵ĵط��������ʦ��Ҫ����Ļ���Ҳ����ѡ����
����С�
 ������������������������������������������������������������
| up   ��    ��ʦ������              ������                  |
| down ��    ��ʦ������                 | (north)            |
| guest��    ӭ����     north: �������ȼ���-west-����������| 
| jail :     ����                                            |
|                    ��POST���桽                            |
|һ���������ʦ�����ڡ���ʦ��������                          |
|�������ɣ��书�����������ڡ����������ҡ�                    |
|�����ײ㿪�������񿪷����������ڡ��������ȼ��ҡ�        |           ���λwiz�ϸ����ع�������Ա��ܹ����õĹ���Ϳ�����   
 ������������������������������������������������������������
  
LONG);
*/

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"system",
  "up" : __DIR__"wizroom1",
  "north" : __DIR__"jobroom",
  "down" : __DIR__"wizroom2",
  "sleeve": __DIR__"sleeveroom",
  "guest": __DIR__"guest",
  "jail":__DIR__"punish",
  "kz": "/d/city/kezhan",
 ]));

  set("wiz_board",1);
  set("coor/x",1000);
  set("coor/y",1000);
  set("coor/z",1000);

  setup();
  call_other("/obj/board/wizard_b", "???");
}

void init()
{   
        if (!wizardp(this_player()))
          add_action("block_cmd","",1);   
}

int block_cmd()
{
       string verb = query_verb();

       if (verb=="say") return 0; //allow say
       if (verb=="chat") return 1;
       if (verb=="quit") return 1;
       if (verb=="look") return 1;
       return 1;
}

string room_long()
{
        string msg;
        msg =
"\n"NOR;
        return msg; 
}

