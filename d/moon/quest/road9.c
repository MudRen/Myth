//Cracked by Roath

inherit ROOM;
#include <room.h>
int index=9;
void create ()
{
  set ("short", "��С��");
  set ("long", @LONG

һ���������۵�С�������߶��ǵ�������ͱڡ�
·�Գ�����һ�˶�ߵ�Ұ�ݣ���˵�������־���
��û��

LONG);
  set("exits", ([ /* sizeof() == 3 */
  "west": __DIR__"road"+sprintf("%d",index+1),
  "east": __DIR__"road"+sprintf("%d",index-1),
]));

  setup();
}

void init() {
  object me=this_player();

  me->start_busy(random(2)+1);
  call_out("greeting",1);
}

void greeting() {
    object npc;
  if (present("little elf",this_object()) || present("monster",this_object())) return;
  if (random(2))  npc=new(__DIR__"npc/beauty");
  else   npc=new(__DIR__"npc/beast");
  npc->move(this_object());
  message_vision("·�Բݴ��ಡ���һ���ܳ�һֻ$N��\n",npc);
}

int valid_leave(object me, string dir) {
  object npc;

  if (dir=="east") return 1;

  if (npc=present("monster",this_object())) 
    return notify_fail(npc->name()+"���������ǰ���������\n");

   if (npc=present("little elf",this_object()))
     return notify_fail(npc->name()+"��ס����½��᲻�������ߡ�\n");
  return 1;
}

