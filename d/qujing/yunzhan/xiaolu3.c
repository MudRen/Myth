//Cracked by Roath

//  ����֮�� ������
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/xiaolu1.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "��ͷ");
  set ("long", @LONG

�����Ƕ��ľ�ͷ�ˣ����Կ�������ط�����������������һ
��ʯͷ(stone)�ر�⻬���㲻����ȥ������
LONG);

  set("exits", ([
        "west"  : __DIR__"xiaolu2",
      ]));
  setup();
}

void init()
{
        object ob = this_player();
        remove_call_out("pig_appear");        
        call_out("pig_appear",5,ob);
        add_action("do_push","push");
}

int do_push(string arg)
{

        object ob = this_player();
      
        if ( ! arg || arg != "stone" )
                return notify_fail("��Ҫ��ʲô��\n");

        if( ob->query("max_force") < 500
          &&ob->query("force") < 700 )
                return notify_fail("�����˰��죬����ʲôҲû�з��֡�\n");

        message_vision(HIR"$N���������ϣ����һ���������ͼ�ʯͷ�������ƶ������㿴��һ���������˽�����\n"NOR,ob);
                set("exits/out", __DIR__"shulin1");
                ob->set("force",0);
                remove_call_out("close");
                call_out("close", 5, this_object());
                return 1;
}
void close(object room)
{
        message("vision","ֻ����֨һ����ʯͷ�����˻�����\n", room);
        room->delete("exits/out");
}       
                
void pig_appear(object ob)
{
        
        object pig=new(__DIR__"npc/pig");
        object where=environment(ob);

      if( objectp(present("zhu guai") ) ) return ;
      if( query_temp("done") ) return ;
        message_vision(HIC"��Ȼһ�����紵����һ��ͷ������$N������\n",ob);
        message_vision("�ƺ�����$N�Ǻǵ�Ц�š�\n"NOR,ob);
        pig->move(where);
        ob->set_temp("see_pig",1);
       where->set_temp("done",1);
        return;
}
