
#include <ansi.h>

inherit ROOM;

void init() {

  set("long",@LONG

һƬ�����Ĳݵأ��������ǵ������ǵĽ̾�����ֻ������һ�������
ͨ��Գָ����һ���У�һ�����߹����ĺ��ӱ����ݵصı�������һ��
ʮ�ɶ�ߵ���ˣ��������һ�����(flag)���ڷ�����Ʈ�衣
LONG);

  add_action("do_start",({"raise","gua","sheng","hang"}));
  add_action("do_look","look");

}

int do_look(string arg) {
  object me=this_player();

  if (!arg || arg!="flag") return 0;
  write ("һ�����߼����Ĵ���죬ӭ��Ʈչ��\n");
  if (query("host")) write("��������"+HIY"�����ʥ"+
        query("host")->query("name")+NOR"�������֡�\n\n");
   else write("��̫�󣬿������������д��ʲô��\n\n");
  return 1;
}

int do_start(string arg) {
   object me=this_player();
   object host=query("host");
   object lijing;

   if (!arg || arg!="flag") return notify_fail("��Ҫ��ʲô��\n");
   if (host)
      return notify_fail(host->query("name")+"���ڴ�ռɽΪ���ˡ�\n");   
   if (me->query("combat_exp")<100000)
     return notify_fail("���̫���ˣ��㹦��̫��Ҳ���ȥ��\n");
   if (me->query("dntg/lijing")=="done")
     return notify_fail("���ϴ��Ѿ����������ʥ��ˣ��������������ɡ�\n");

   set("host",me);
   message_vision(HIG"$N���������ʥ���Ĵ��������ˡ�\n"NOR,me);
   message_vision(HIG"$N�������������ӽ�����"+RANK_D->query_self_rude(me)
     +"���������ʥ��������϶�ƽ��ƽ������\n"NOR,me);

  lijing=new("/d/dntg/lijing/lijing");
  lijing->move(environment(me));
  lijing->set("target",me);
  lijing->start();
   
  return 1;
}
