// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/yuandoor.c

#include <room.h>
inherit ROOM;

void create ()
{
	set ("short", "԰��");
	set ("long", @LONG

һ��С���š�����д�š���԰�����֡���ǰ����ɭ�ϡ���ע��
�����Ϲ���һ��������������ȥ��Ϊ���ס�

LONG);

	set("exits", 
	([ //sizeof() == 4
		"southwest" : __DIR__"ting",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/shoumenyao" : 2,
	]));

	setup();
}
int valid_leave(object me, string dir)
{
  if (dir == "north" && 
      member_array("hu xianfeng",me->parse_command_id_list())==-1)
    return notify_fail("����Ϊ˭�������������԰��?\n");
  return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{
        object me, key, nroom;

        me = this_player();

        if( !arg || arg != "door" ) 
                return notify_fail("��Ҫ��ʲô��\n");

        if( !(key = present("jin yaoshi", me)) ) 
                return notify_fail("û��Կ����ô���ţ�\n");

        //now we are ready to open...
        if( !(nroom = find_object(__DIR__"yuan")) )
                nroom = load_object(__DIR__"yuan");

        set("exits/north", __DIR__"yuan");
        nroom->set("exits/south", __FILE__);
        message("vision", "���ó�Կ�ף������š�\n", this_object() );

        me->set_temp("used_huangtong_key", 1);
        destruct(key);
        return 1;
}