
//xiaowu2.c Ѱľ��
inherit ROOM;
int do_find(string arg);
void create()
{
        set("short", "Сé��");
        set("long", @LONG
����һ����ª��Сé�ݣ�����ǽ�Ϲ���һ���������������˵���Ҳ��߳����ơ�
����ǽ������һ��ʫ��
        ���鵺�ϱ��죬���й��������ߡ�
        һ��������ˮ�棬Ը��ʰ��ϧ������
LONG
        );
   set("exits", ([
      "east" : __DIR__"xiaowu",
   ]));
   setup();
}
void init()
{
 add_action("do_find","xunzhao");
}
int do_find(string arg)
{
 object who=this_player();
 object ob;

 if(who->is_busy()) return notify_fail("����æ���أ�\n");
 if(!who->query("search_for_mujian"))
    return notify_fail("�����Ǳ��˵ļң�����������\n");
        if(!arg || arg != "ľ��")
           return notify_fail("��Ҫ��ʲô��\n");
        who->start_busy(3);
 message_vision("$N������ϸ�ķ�Ѱ������ʲô��û�ҵ���\n",who);
 message_vision("$N��������ϸ���ҡ�\n",who);
 if(random(3) == 2)
 {
  message_vision("$N�����쵽����������ͻȻ��$N����������һ��Ӳ�\n",who);
  message_vision("$N������һ������Ȼ�Ǳ�ľ����\n",who);
  ob = new(__DIR__"obj/mujian");
  ob->move(who);
 }
 else
     return notify_fail("����˰��쾢������ʲô��û�ҵ���\n");
 return 1;
}
