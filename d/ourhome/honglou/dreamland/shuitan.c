
//shuitan.c Ѱˮ����
#include <ansi.h>
inherit ROOM;
int do_dive();
void create()
{
        set("short", "ˮ̶");
        set("long", @LONG
ӭ����һ���ٲ���������һ���޴��ˮ̶���ٲ���к��ˮ̶���������ľ��졣
�ɽ���ˮ���������³����������Ĳʺ硣̶������ɫ����������ȥ��
LONG);
   set("exits", ([
      "northeast" : __DIR__"shangu2",
   ]));
   set("resource", ([
      "water" : 1,
   ]) );
set("outdoors",1);
   setup();
}
void init()
{
   add_action("do_dive","dive");
}
int do_dive()
{
   object zhou,who,room;

   who = this_player();
   if(( !(zhou=present("bishui zhou", who))
 ||(string)zhou->query("unit")!="��")
 && (string)who->query("family/family_name")!="����"
 && (string)who->query("family/family_name")!="��������")
 return notify_fail("��һ����������ˮ�����\n"+
                           "\n��û�����ͱ���ð�����ֻ�øϽ����ϰ�����\n");
   message_vision(HIY "$Nһ����������ˮ�У�Ȼ�󲻼��ˣ�\n" NOR, who);
   if(!( room = find_object(__DIR__"tandi")) )
   room = load_object(__DIR__"tandi");
   if(objectp(room))
   {
        who->move(room);
        message_vision("$NǱ����̶�ס�\n",who);
   }
   return 1;
}
