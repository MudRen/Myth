//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/huangfeng/road1.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

����ط�����Ѭ�죬ʱ����Щ���ӣ�����ʲô����������
����һ̲�����Ѿ�����˺�ɫ��
LONG);

  set("exits", ([
        "north"   : __DIR__"dongkou",
      ]));
  setup();
}
void init()
{
        object ob = this_player();
        if( !ob->query_temp("winded") )
                return;
        remove_call_out("appear");
        remove_call_out("bite");
        remove_call_out("fly");
        call_out("appear",3,ob);
        call_out("bite",8,ob);
        call_out("fly",12,ob);
}
void appear(object ob)
{
        object wenzi=new(__DIR__"npc/wenzi");
        object where=this_object();
        if( present("wen zi") )
        return;   
        message_vision(HIC"��֪��ʲô�ط�����һֻ���ӡ�\n"NOR,ob);
        wenzi->move(where);
}
void bite(object ob)
{
        message_vision(HIC"��Ȼ������$N�������Ͷ���һ�ڡ�\n"NOR,ob);
        ob->add("kee",-50);
}
void fly(object ob)
{
        object wenzi=present("wen zi");
        message_vision(HIC"�������˵ķ����ˡ�\n"NOR,ob);
        destruct(wenzi);
}
