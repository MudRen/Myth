
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create() {
  set("short", "���ʹ�");
  set("long", @LONG
    
һ���񵭹��ţ��߲������Ŀ�󹬵�����������㰸��
���Ϸ����������̣����ڹ��ż��������õľ�ת�𵤡�¥
����̫���Ͼ����������굤̨�����������Ͼ�����ˬ�ʵ�
����������ȴ�Ҳ�����¥�Ľ��ݡ�������һ�����ţ�����
����һ������ͼ�������ھ����Ͼ������ĵ�����

LONG );


  set("exits", ([
    "west"   : __DIR__"danfang",
    "out" : __DIR__"gate",
  ]));

  set("objects",([
    __DIR__"obj/jindan": random(2)+1,
    __DIR__"npc/daoshi": 1,
  ]));

  setup();
}

void init() {
  add_action("do_get",({"get","eat"}));
  if (userp(this_player()))   call_out("force_leave",300,this_player());
}

void force_leave(object me) {
  if (! environment(me) || environment(me)!=this_object()) return;
  message_vision(HIB"���д���̫���Ͼ������������������Ҷ��ʹ�����������\n",me);
  message_vision("$N�������飬�ŵû겻���壬ת��һ�����ӻػ���ɽȥ�ˡ�\n"NOR,me);
  me->move("/d/dntg/hgs/flowerfruit");
  if (me->ride()) me->ride()->move(environment(me));
}
int do_get(string arg) {
   object daoshi;
   if (!arg) return 0;
  
   daoshi=present("dao shi",this_object());
   if (daoshi && living(daoshi)) {
      daoshi->command("hmm");
      daoshi->command("waggle "+this_player()->query("id"));
      this_player()->start_busy(1);
      return 1;
   }
   return 0;
}

int valid_leave(object me, string dir) {
    if ( dir == "west")
      return notify_fail("��Χ�Ű��������˼�Ȧ���ֻص���ԭ�ء�\n");
    return ::valid_leave(me, dir);
}
  
