// Room: /u/mimi/zhuziguo/yuhuayan.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "����԰");
  set ("long", @LONG

����԰�Ѿ�������꣬԰�г����Ѿ��ɿݣ��������ᾡ�ʡ����յ�
�滨��ݾò��������ѱ��Ҳ���û��Ω��ǽ�ǵ�һ�ðŽ�������
ïʢ(bajiao)�����ڻ�ľ��ͬ��
LONG);

  set("outdoors", __DIR__"");                   
  set("item_desc", ([ /* sizeof() == 1 */
    "bajiao" : "һ�������㣬�������Կա�����ǧ��ϸ������һ��졣\n"+
               "�������㻧����Ӱ�����С���������ɫ�������ǽ����\n",
    ]));
  set("exits", ([ /* sizeof() == 1 */
    "out" : __DIR__"huilang2.c",
  ]));

  setup();
}

void init()
{
  add_action("do_kan", "kan");
}

int do_kan(string arg)
{
  object me = this_player();
  object ob;

  if ((!arg) || !((arg == "bajiao") || (arg == "�Ž�")))
    return notify_fail("��Ҫ��ʲô��\n");

  if (!(ob = me->query_temp("weapon")) ||
     (string)ob->query("skill_type") != "axe")
    return notify_fail("��ȥ�ҰѸ�ͷ�ɣ�\n");

  if (sizeof(query("exits"))>1)
    return notify_fail("�Ž����Ѿ����ˣ�\n");
  
  message_vision("$N������ӳ��Ž�����ȥ���Ž������˻Ρ�\n",me);
  if (me->query("kee") <= 40)
    me->unconcious();
  me->add("kee",-40);
  if (random(50-me->query_kar()) < 5)
  {
    message_vision("ֻ�����һ�����Ž������ˣ�����¶��һ�ھ���\n",me);

    set("exits", ([ 
      "out" : __DIR__"huilang2.c",
      "down" : __DIR__"well",
    ]));
    return 1;
  }
  return 1;
}
