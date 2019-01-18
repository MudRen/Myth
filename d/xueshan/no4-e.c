//sgzl
inherit ROOM;

int check_food ();
int come_she ();
int back_she ();

void create ()
{
	set ("short", "ѩ��");
	set ("long", @LONG

ѩ��ľ�ͷ��һ��СС�Ķ�(cave)����˵������һֻ����
С�ߣ����˺���Դ󲹣�����ô�����Ӷ������������ɾ�
û������֪���ˡ�
LONG);


        set("item_desc", 
        (["cave" : 
             "һ��С��������ںڵģ�ʲô����������\n", 
        ]));

	set("exits", 
	([ //sizeof() == 4
                "west" : __DIR__"no4-enter",
	]));
	
	set("objects", 
	([
	]));


        set("she_time",1);

	set("outdoors", "xueshan");

	setup();
}

void init()
  {
   remove_call_out ("check_food");
   call_out ("check_food", 5);
  }

int check_food ()
  {
  object who =this_player();
  object where = this_object();
  object douzi;

  if (present ("jiu dou", where)) 
        douzi = present ("jiu dou",where);
  if (douzi && douzi->query("value")==20000 && 
        ! present ("chilian xiaoshe", where)) 
        call_out ("come_she",3);
  remove_call_out ("check_food");
  call_out ("check_food",3);
  return 1;
  }

int come_she ()
  {
    object she;
    object where = this_object();
    object douzi = present ("jiu dou",where);
    object who =this_player();
    int stay_time=where->query("she_time")*2;

    if (douzi && douzi->query("value")==20000)
      {
       tell_room(where,"һֻС�ߴӶ������˳�������"
          +douzi->query("name") +"�������\n",who);
       she=new("/d/xueshan/npc/she");
       she->move(where);
       destruct (douzi);
       call_out ("back_she",stay_time);
      }
    return 1;
  }

int back_she ()
  {
  object where = this_object();
  object who =this_player();
  object she = present ("chilian xiaoshe",where);

    if (she)
      {
       tell_room(where,she->query("name") +
          "������һ��������ȥ��Ȼ����������ض��\n",who);
       destruct (she);
       where->add("she_time",1);
      }
  return 1;
  }
