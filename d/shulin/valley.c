// /d/shulin/valley.c�ط�����ĵط�
inherit ROOM;
int do_out();
void create()
{
        set("short", "����");
        set("long", "����һ��ɽ�ȣ����������������������ӡ�\n");
        set("objects", ([
             __DIR__"npc/shuyao" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
 add_action("do_out","out");
}
int do_out()
{
 object room;
 object who = this_player();
  message_vision("$N��������������ͻȻһ�ɺ��紵����$Nȫ���������ˣ�\n",who);
  who->recieve_damage(who->query("kee")/5);
  who->recieve_wound(who->query("max_kee")/5);
  who->start_busy(5);
  who->move("/d/shulin/lin8");
  return 1;
}
