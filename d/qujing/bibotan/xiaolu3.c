#include <room.h>
inherit ROOM;
void create ()
{
  set ("short", "̶��С·");
  set ("long", @LONG

С·��Ϊ��������߶��Ĺ�ϵ���ѱ��ݻƵ���Ҷ�����ˡ�·�ߵ�
�Ĳݼ����˸ߣ���紵��������һƬƬ�Ŀ�Ҷ���ݴ���Ҳ������
�죬�������޷����ĺ�����
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"gudu",
  "northwest" : __DIR__"xiaolu4",
]));

  setup();
}

void init()
{       
        object me=this_player();
        if( !present("shuishe guai") || interactive(me)) {
                remove_call_out("greeting");
                call_out("greeting",5, me);
        }
}
void greeting(object me)
{       object jing, guai;
        if( !me || environment(me) != this_object() ) return;
        if( present("shuishe guai") ) return;
        seteuid(getuid());
        if(guai=new("/d/qujing/bibotan/npc/shuiguai"))
                guai->move(this_object());

        seteuid(getuid());
        if(jing=new("/d/qujing/bibotan/npc/shuiguai"))
                jing->move(this_object());

                message("vision", "\n̶�е�ˮ���˶������������������\n\n", this_object() );
                message_vision("ˮ�߹ֿ���$N��Ц���ö���û�����ˣ�������\n\n", me);
        jing->kill_ob(me);
        me->fight_ob(jing);
	guai->kill_ob(me);
        me->fight_ob(guai);

}

