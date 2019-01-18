// Room: /d/ourhome/xiaoting.c
//cglaem...12/15/96.


#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_stand(string temp2);
int do_sit(string temp3);
int do_out(object ob);

void create()
{
        set("short", "�ۼ�ͤ");

	set("long", @LONG

--�� �� ͤ-- 

����壬�����
��Ҷ�ۻ�ɢ
��ѻ�ܸ��� 
��˼���֪����
��ʱ��ҹ��Ϊ��

�ɴ������ɿ���һ���Ľ�С·������������������
�������ʵ�ʲôҲ�����塣������ԼԼ�ؾ���ֻҪ
�����������һ��(out)Ҳ�����Զ�ز����ˡ�
LONG
	);


	set("exits", ([
	"north" : __DIR__"kedian4",
	]));

  set("objects", ([ 
               __DIR__"obj/table" : 1,
               __DIR__"obj/seat" : 2,
        ]));
                                              
        set("no_fight",1);
              set("no_magic", 1); 
	set("no_clean_up", 0);
      
	setup();     
}

void init()
{
	add_action("do_stand", "stand");
	add_action("do_sit", "sit");
 	add_action("do_out","out");
}

int do_sit(string arg)
{     
      object me;

      me=this_player();

	if ( !arg || ((arg != "seat")&&(arg != "table") ))
		return notify_fail("��Ҫ����ʲô���棿\n");	
	
	if (this_player()->query_temp("marks/sit"))
		return notify_fail("���Ѿ������ˡ�\n");	
      
      if ( arg != "seat")	
	      return notify_fail("�������ϣ�̫���Ź��˰ɡ�\n");
        	
	this_player()->set_temp("marks/sit", 1);
	message_vision("$N�����������ʯ�����������������˶����ȡ�\n",me);
      return 1;	
}

int do_stand(string arg)
{
      object me;

      me=this_player();

      if (!this_player()->query_temp("marks/sit"))
          return notify_fail("�㱾����վ�š�\n");

      this_player()->set_temp("marks/sit", 0);
      message_vision("$N���˸�������վ��������\n", me);
      return 1;
}

int do_out(object ob)
{
        ob = this_player();
        write(HIB "������������һ����һ��Ũ���������������\n" NOR);

        message("vision", sprintf(HIB+"%s�����������һ����һ��Ũ�����������\nһգ�۵Ĺ���%s�Ͳ����ˡ�\n"+NOR, ob->name(), ob->name()), environment(ob),({ ob }));
        write(RED "����ǰһ��ڣ�����\n\n\n" NOR);
        ob->move("/d/dntg/hgs/entrance");
        write(HIY "\n������ϼ��һ�����㷢���Լ�������һ��İ���ĵط���\n\n" NOR);
        message("vision", HIY 
        "ֻ�����춯�ص�һ�����죬������ϼ���������ʯ����---\n"+
        "��Ȼ������ĳ�һ��������\n" NOR, environment(ob),  ({ ob }) );
        return 1;
}


int valid_leave(object me, string dir)
{
	object mbox;

	if( mbox = me->query_temp("mbox_ob") ) {
		tell_object(me, "�㽫���佻�ظ��ʲ\n");
		destruct(mbox);
	}
	return 1;
}

