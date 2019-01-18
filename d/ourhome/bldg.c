

// Room: /d/city/bldg.c

#include <ansi.h>
inherit ROOM;

/*void init(); */
int do_go(string temp2);
int do_sit(string temp3);

void create()
{

      set("short", "סլ��");
	set("long", @LONG
��춼��������ˡ�����������һƬû�п�����סլ����
�����Ӳݴ��������˼����಻�����С�������������ȥ
�⣬���и����ϸ��Ŷ��Ʋ�ñ�����ˣ�������һ����ү
��(car)�ϴ��˯�� 
LONG
	);

	set("exits", ([
		"north" : __DIR__"kedian3",
	]));
	
    set("item_desc", ([
          "car":"һ���������ҵ���ү����ֻ��������λ�� \n",
	]));
	                                

	set("objects",([
		__DIR__"npc/driver" : 1,
		]));
	
	set("no_fight", 1);
	
	setup();
}

void init()
{
	add_action("do_go", "drive");
	add_action("do_sit", "sit");
}


int do_go(string arg)
{

	object me;
	object driver; 

	me=this_player();
	if( !objectp(driver = present("driver", environment(me))) )
           {     return notify_fail("˾��û�ڣ���õȻ����� \n");
           }

      if( !me->query_temp("marks/sit") )  
        {	return notify_fail("�㻹û�ϳ��ء�\n");
        }

 
	if (!arg)
	{
		return notify_fail("��Ҫȥ���\n");	
	}
	if ( file_size("/u/"+arg+"/workroom.c")<0)
	{
	   message_vision("˾�������ض�$N˵�����Ҳ��ǵø�������һ�ҡ�\n",me);
         return notify_fail(""); 
	}

		
	 			
	
	message_vision("˾���Ͳ����ţ���ү��ƨ����ð��һ�����̣���ǰ��ȥ��\n", me);
      message_vision("$N���ûˤ������\n", me);
	
      me->move("/u/"+arg+"/workroom.c");
      
      message_vision("����һ���̶���ɷ������ֻ��$N���Ƽ������˳�����\n", me);
      this_player()->set_temp("marks/sit",0);
	return 1;
}


int do_sit(string arg)
{

	if ( !arg || (arg != "car") )
		return notify_fail("��Ҫ��ʲô��\n");	
	
	if (this_player()->query_temp("marks/sit"))
		return notify_fail("���Ѿ��ϳ��ˡ�\n");	
			
	this_player()->set_temp("marks/sit", 1);
	return notify_fail("��С�������������ͷ���Ǳ�����һ�¡�\n");	
}


