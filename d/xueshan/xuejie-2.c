//sgzl
inherit ROOM;

void create ()
{
	set ("short", "ѩ��");
	set ("long", @LONG

·�ֵ��˾�ͷ����(jump)��ǰ���ʯ��(shi bi)�Ϳɽ���
ѩɽ�ĵ�����ɽ�ˡ�
LONG);


	set("exits", 
	([ //sizeof() == 4
                "south" : __DIR__"wuchang-n",
	]));
	
	set("objects", 
	([
	]));


	set("outdoors", "xueshan");

	setup();
}

void init()
{
        add_action("do_jump", "jump");
}


int do_jump(string arg)
{       
        object me;
        me=this_player();

        if ( !arg || ((arg != "shi bi") ))
                return notify_fail("��Ҫ��������\n");
        else if(me->query("kee")<50)   
          {
           message_vision("$N����һ������������������ˤȥ��\n",me);
           me->unconcious();
          }
	else
          {
           me->add("kee",-50); 
           message_vision("$N����һԾ�����ɵķ���ʯ�ڡ�\n",me);
           me->move("/d/xueshan/shanpo");
           tell_room(environment(me),"ֻ��"+me->name()+"����Ծ��������\n", me);
           return 1;
           }
        return 1;
}

