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
  "southeast" : __DIR__"xiaolu3",
  "westup" : __DIR__"shipo1",
]));

  setup();
}

void init()
{       
	object me=this_player();
	if( !present("liushu jing") || interactive(me)) {
		remove_call_out("greeting");
		call_out("greeting",5, me);
	}
}
void greeting(object me)
{	object jing;
	if( !me || environment(me) != this_object() ) return;
	if( present("liushu jing") ) return;
	seteuid(getuid());
	if(jing=new("/d/qujing/bibotan/npc/shujing"))
		jing->move(this_object());
		message("vision", "\nһ���ʷ紵�������������¸���������\n\n", this_object() );
		message_vision("����������$N��Ц�����ŵ�������������\n\n", me);
	jing->kill_ob(me);
	me->fight_ob(jing);

}
