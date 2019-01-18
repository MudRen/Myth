//Cracked by Roath
// Room: /changan/eastseashore.c

#include <ansi.h>
inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_zuo(string arg);
int do_dive();
void reset();


void create ()
{
  set ("short", "����֮��");
  set ("long", @LONG

��ǰ���Ƕ�����ãã���������߼ʡ������ϲ�����ӿ������
�ߵ���ͷ����˷�������Ҫ����һ�и��ڵ����ϵĶ�����Ҳ��
�������·�ľ�ͷ����ǰ�Ĵ󺣶�һ��������˵�ǲ�����Խ�ġ�
�밶��Զ��Ư��һֻľ��(mufa)��
LONG);

  set("objects", ([
   __DIR__"npc/jingwei":1,
  ]));
  set("item_desc", ([ /* sizeof() == 1 */
  "mufa" : "һֻľ�����Լ�����Բľ���ɡ��㲻������(zuo)��ȥ��һ�ԡ�
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"seashore2",
 "eastup" : "/d/lanling/lanlingxi3",
]));

       set("outdoors", 1); 
  setup();
}

void init()
{
    add_action("do_zuo", "zuo");
    add_action("do_zuo", "sit");
    add_action("do_dive", "dive");
    add_action("do_swim", "swim");
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"mufa")) )
            room = load_object(__DIR__"mufa");
        if( room = find_object(__DIR__"mufa") ) {
            if((int)room->query("zuo_trigger")==0 ) {
                room->set("zuo_trigger", 1);
                set("exits/enter", __DIR__"mufa");
                room->set("exits/out", __FILE__);
                message("vision", "һֻľ���Ӻ���Ư�˹�����\n", this_object() );
                message("vision", "ľ��һ����Ȼ�Ǹ�ǳ�ˡ�\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "ľ����Ư�򰶱ߣ������ӻ������ĵصȵȡ�\n",this_object() );
        }
        else
            message("vision", "ERROR: mufa not found\n", this_object() );
    }
    else 
        message("vision", "ľ���Ѿ������ˣ���ʱ������ȥ��\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "һ����ͷ������ľ������Ưȥ��\n",
        this_object() );

    if( room = find_object(__DIR__"mufa") )
    {
        room->delete("exits/out");
        message("vision", "��Χ�ǰ�ãã��һƬ�����Ѿ��������κ�½�صļ�����...\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"mufa") )
    {
        room->set("exits/out", __DIR__"aolaiws");
        message("vision", "ľ��һ�𣬸�ǳ�ˡ���Ȼ�ǵ�½���ˣ��Ͻ���ȥ�ɡ�\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"mufa") ) {
        room->delete("exits/out");
        message("vision","һ����ͷ������ľ������Ưȥ��\n", room);
room->set("zuo_trigger", 0);
    }
}

int do_zuo(string arg)
{
    string dir;

    if( (arg=="mufa") || (arg=="ľ��")){ 
        message_vision("$N����������ľ����\n", this_player());
        check_trigger();
        return 1;
    }
    else return notify_fail("��Ҫ����ʲô��\n");
}

int do_dive()
{       object me, zhou;
    object ridee;
        me=this_player();
   ridee=me->ride();



	    if(( !(zhou=present("bishui zhou", me))
		||(string)zhou->query("unit")!="��")
		&& (string)me->query("family/family_name")!="����"
		&& (string)me->query("family/family_name")!="��������")

		return notify_fail("��һ����������ˮ�����\n"+
		  "\n��û�����ͱ���ð�����ֻ�øϽ����ϰ�����\n");
  me->start_busy(1);

   if (ridee && ridee->query("under_water")) {
     message_vision(HIY"$Nһ��$n��ͷ�����˴���Ծ��ˮ�С�\n"NOR,me,ridee);
     ridee->move("/d/sea/under1");
  }

      else  message_vision(HIY "$Nһ����������ˮ�У�Ȼ�󲻼��ˣ�\n" NOR, me);
                me->move("/d/sea/under1");
		message_vision("$NǱ�˹�����\n",me);
                return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"mufa") )
        room->delete("zuo_trigger"); 
}
int do_swim()
{
        object  me, horse;
	me = this_player();
message_vision(HIY "$N����һԾ�����뺣�С�ֻ��$Nʹ����ȫ�����������㲢�ã���һ������ε����ڽ��ߡ�\n" NOR, me);
me->move("/d/sanjie/wujiang0");
message_vision(HIY "ֻ��$N����ʪ�����شӺ�������������\n" NOR, me);
me->receive_damage("kee", 20);
me->receive_damage("sen", 20);
return 1;
}
