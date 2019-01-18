 // Room: /shulin/lin8.c
inherit ROOM;
int do_enter(string arg);
void create()
{
        set("short", "����");
        set("long", @LONG
�����߳������֣��㲻�����������˿��������������������
�����ϣ�ʹ��е��ޱȵ���ů���ϱ���һ�����ʵ�ʯɽ��ɽ������
�Բԣ�������ľ��ɽ���ƺ��и�С��(cave)��
LONG );
        set("outdoors", "xiakedao");
        set("exits", ([
              "north" : __DIR__"lin7",
              "south" : "/d/calvin/milin/milin",
              "east" : "/d/shulin/lin9",
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
 add_action("do_enter","enter");
}
int do_enter(string arg)
{
 object room;
 object who = this_player();
 if(!arg || arg != "cave")
    return notify_fail("��Ҫ�����\n");
if(random(who->query_kar())>25 && who->query("max_mana")>1000)
 {
  if(!( room = find_object(__DIR__"valley")) )
                room = load_object(__DIR__"valley");
                if(objectp(room))
             {
              message_vision("$N�����С������ǰ��Ȼһ����ԭ���Ǹ������ʻ���Сɽ�ȣ�\n",who);
              who->move(room);
             }
         return 1;
     }
     else
{
message_vision("$N��������������ͻȻһ�ɺ��紵����$Nȫ���������ˣ�\n",who);
who->recieve_damage(who->query("kee")/5);
who->recieve_wound(who->query("max_kee")/5);
who->start_busy(5);
return 1;
}
}
