//sgzl
inherit ROOM;

int check_hudie ();

void create ()
{
	set ("short", "ѩ��");
	set ("long", @LONG

�����Ʈ���ѩ����ס��������ߣ�ֻ����������ǰ
�����һ��СС��֩����(net)��
LONG);


        set("item_desc", 
        (["net" : 
             "һ��֩������\n", 
        ]));

	set("exits", 
	([ //sizeof() == 4
                "south" : __DIR__"no4-w1",
                "west" : __DIR__"no4-wn2",
	]));
	
/*
	set("objects", 
	([
	]));
*/

	set("outdoors", "xueshan");

	setup();
}

void init()
  {
   remove_call_out ("check_hudie");
   call_out ("check_hudie", 5);
  }

int check_hudie ()
  {
  object where = this_object();
  object hudie;

  if (present ("hu die", where)) 
    {
     hudie = present ("hu die",where);
     remove_call_out ("catch_hudie");
     call_out ("catch_hudie",3);
    }
  remove_call_out ("check_hudie");
  call_out ("check_hudie", 5);
  return 1;
  }

int catch_hudie ()
  {
  object who=this_player();
  object where = this_object();
  object hudie;


  hudie = present ("hu die",where);
  if (present ("hu die", where))
  {
  message_vision("$N��һ�ɾ޴�����������֩������\n", hudie);
  tell_room(environment(hudie),hudie->name()+"�����˽�����\n", who);
  hudie->move(__DIR__"zhuwang"); 
  }
  return 1;
  }
