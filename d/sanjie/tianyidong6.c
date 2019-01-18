// sanjie tianyifu.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
	
����ͻȻһ����������ʯ�����и��ܴ�İ��ԣ������л���
һ��С����(hole)����֪����ʲô������ȥ���������ȷ��
���ء�
LONG);
  set("item_desc", ([
  "hole" : "�����ƺ��Ǹ����أ�һ�����԰��С���ܷ�(insert)��ʲô������\n",
]));
  set("exits", ([ 
  "southwest" : __DIR__"tianyidong4",
  "southeast" : __DIR__"tianyidong5",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/qiuxuke": 1 ]) );
  setup();
}
void init()
{
	add_action("do_insert", "insert");
}
int do_insert(string arg)
{
        object enterroom, ob, me;
	me=this_player();
	if( !arg )
		return notify_fail("��Ҫ��ʲô������\n");

        if( !arg || arg!="fuxi bagua" || !(ob=present(arg, me)) || ob->query("name")!=HIC"���ذ���"NOR )
		return notify_fail("�ƺ����зŲ������������\n");


        if( !(enterroom = find_object(__DIR__"tianyifu")) )
            enterroom = load_object(__DIR__"tianyifu");
        if( enterroom = find_object(__DIR__"tianyifu") ) 
        {
                set("exits/enter", __DIR__"tianyifu");
                message_vision("$N��$n����С�ף�ֻ����������������ͼ�����˱仯��¶������һ��ͨ�ڡ�\n", me, ob);
                message("vision", "��ʯ���˴����ƿ��ˡ���\n", enterroom );
		enterroom->set("exits/out", __DIR__"tianyidong6");
		destruct(ob);
        call_out("close_down", 10);
	}
	return 1;
}

void close_down()
{
        object enterroom;

        message("vision", "ǽ�ں���ֻص�ԭλ��\n", this_object() );
        if( enterroom= find_object(__DIR__"tianyifu")) {
        message("vision", "ǽ�ں���ֻص�ԭλ��\n", enterroom);
        enterroom->delete("exits/out");
        }

        delete("exits/enter");

}