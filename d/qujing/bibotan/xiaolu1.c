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
  "southwest" : __DIR__"gudu",
  "northeast" : __DIR__"xiaolu2",
]));

  setup();
}

void init()
{       
        object me=this_player();
	if( query("done") ) return;
        if( !present("laohu jing") || interactive(me)) {
                remove_call_out("greeting");
                call_out("greeting",5, me);
        }
}
void greeting(object me)
{       object jing;
        if( !me || environment(me) != this_object() ) return;
        if( present("laohu jing") ) return;
        seteuid(getuid());
        if(jing=new("/d/qujing/bibotan/npc/laohujing"))
                jing->move(this_object());
                message("vision", "\nһ���ȷ紵�����Ӳݴ����������������\n\n", this_object());
                message("vision","�ϻ�����е���������Ҫ����ȥ�¾ƣ��Թ�Ͷ���ɣ���ô������֣����Կ�ͷ��\n\n",
this_object());
        jing->kill_ob(me);
        me->fight_ob(jing);

}
