// fangjian2.c
// by lestat

inherit ROOM;

void create()
{
        set("short", "�һ���");
        set("long", @LONG
����һ�䲼�ó�����ģ����С���䣬����ʯ�������ϰ��Ÿ�СС��ľͷ
�Ƴɵ�ҡ����ǽ��������һ�������٣����߶��Ѿ����ˡ�
LONG );
       set("exits", ([
               "south" : __DIR__"shiji2",
       ]));

	    set("objects",([
		__DIR__"npc/niang" : 1,
		"/d/pansi/obj/qin.c":1, 
	]));
	
       set("no_clean_up", 0);
       setup();
}

void init()
{
        add_action("do_han", "han");
}

int do_han(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="֥�鿪��") 
	{
		tell_object(me,"�����˵������ǽ�ڴ��һ������֥�鿪�ţ���\n");
		message("vision", "����һ�������ֻ����һ���¡¡��������������һ�����š�\n", me);
		set("exits/down", __DIR__"shishi4");
		remove_call_out("close");
		call_out("close", 5, this_object());
		return 1;
	}
}

void close(object room)
{
	message("vision","һ���¡¡����������ʯ���ֻ����ع����ˡ�\n", room);
	room->delete("exits/down");
}
int valid_leave(object me,string dir)
{
        if(dir=="down" && (!me->query("family") || (me->query("family/family_name")!="��˿��")) && present("niang",environment(me))) 
             return notify_fail("��ʮ����һ��������ס�����ȥ·��\n");
        return ::valid_leave(me,dir);
}