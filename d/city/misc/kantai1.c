//Cracked by Roath

inherit ROOM;

void start(object leitai1) {leitai1->start();}

void create ()
{
  set ("short", "С����̨");
  set ("long", @LONG

����̨��ƽ̹���ʵĺ�ľһ������ɣ��������Ż��ƻ�Ƥ�ͽ�Ǯ��
Ƥ��̨�Ϸ���һ�����ɺ�����̫ʦ�Σ������ù���ǱȽ����ʵع�
������������ѡ��Ҳ�����������ѯ(checkscore)�Լ���ս������
һ�����ֵ�����(list)��

LONG);

  set("exits", ([
        "east"   : "/d/city/wuguan",
//     "up"  :  __DIR__"leitai",
      ]));
  set("no_fight",1);
set("objects",
([ //sizeof() == 2
    "/d/city/npc/caipan" : 1,
    __DIR__"scorekeeper":1,
]));  
  set("no_magic",1);
  setup();
}

void init() { 
  add_action("do_defend","defend");
  add_action("do_checkscore","checkscore");
  add_action("do_list","list");
}
/*
int do_list() {
  int size;

  object room=find_object(__DIR__"leitai1");
  if (!room) room=load_object(__DIR__"leitai1");
  size=room->query("size");
  if (size>10) size=10;
  if (!size) return 1;
  write("����    �ɣ�        ����\n");
  for (int i=1;i<=size;i++) {
  write(sprintf("%2d      %-8s    %d\n",i,room->query("list/"+i),room->query("scores/"+room->query("list/"+i))));
  }
  write("\n");
  return 1;
}
int do_checkscore() {
  object room=find_object(__DIR__"leitai1");
  if (!room) room=load_object(__DIR__"leitai1");
  room->report(this_player());
  return 1;
}
*/

int do_list() {
  write("�йظ�����˽�����ǲ�Ҫ���ʵĺá�\n");
  return 1;
}
int do_checkscore() {
  write("���Լ��ĳɼ���ô�����Լ����������\n");
 return 1;
}
int do_defend(string arg) {
  object defender=this_player(); 
  object challenger;
  object leitai1=find_object(__DIR__"leitai1");

  if (!arg) return notify_fail("��Ҫ��˭Ӧս��\n");
  if (!challenger=present(arg,this_object()))
      return notify_fail("����û������ˡ�\n");
//
  if (!userp(challenger))      return notify_fail("���ﲻ�ܺ�����������̨��\n");
  if (!userp(defender))      return 1;
//  if (challenger->query_temp("leitai/challenge")!=defender)
 //    return notify_fail("����û��������ս��\n");

  if (!leitai1) leitai1=load_object(__DIR__"leitai1");
  if (leitai1->query("busy")) 
    return notify_fail("����������̨�Ͻ��֣����Ժ�\n");  

  message_vision("$N����$n����ս��\n",defender,challenger);
  if (defender->move(leitai1) && challenger->move(leitai1)) {
    defender->delete_temp("leitai1/being_challenged");
    challenger->delete_temp("leitai1/challenge");
    leitai1->set("player1",defender);
    leitai1->set("player2",challenger);
    leitai1->set("busy",1);
    call_out("start",5,leitai1);
   }
  return 1;
}
int valid_leave(object who,string dir) {
  if (!wizardp(who) && dir=="up") return 0;
  return 1;
}
