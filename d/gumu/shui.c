// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short", "����");
 set("long", @LONG
һƬ����ɢ���Ÿ��õ���ζ��������ϡ�õ���Ͷ��ĵ�
���˲����½ţ�һ�����������䶯�ţ�Ѱ���Ź������ʱ
��......
LONG
 );
 set("exits", ([
  "south" : __DIR__"huo",
  "north" : __DIR__"tu",
  "east" : __DIR__"jin",
  "west" : __DIR__"mu",
]));

 set("coor/x",10);
 set("coor/y",-620);
 set("coor/z",-20);
 setup();
}
void init()
{ object ob;
 if( interactive( ob = this_player()))
 call_out("blowing", random(10) + 1, ob);
 add_action("do_chop","chop");
}
int blowing(object ob)
{
 int i;
 int damage;
        if(  ob && environment(ob) == this_object())
 {
 tell_object(this_object(), HIG "\n\nͻȻһ�����ߴ��Աߴ��˳�������\n\n" NOR);
 COMBAT_D->report_status(ob,1);
 ob->receive_wound("kee", random(20)+10);
 if( environment(ob) == this_object())
 call_out("blowing",random(10)+1, ob);
 }
 else
 return 1;
}
void reset()
{
 ::reset();
        remove_call_out("blowing");
        delete("exits/east");
}
int valid_leave(object me, string dir)
{
        remove_call_out("blowing");
 return 1;
}



