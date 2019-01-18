// Room: /d/qujing/wudidong/south
inherit ROOM;

void create()
{
  set ("short", "���");
  set ("long", @LONG

���͸����ư��ˡ�һ��ǽ��ǰ������һ��������(statue)��������
�ϵ������Ѱ��䣬��Ȼ����������������ꡣ�����˶�˵�����ֹ�
Ҳ��֪�����Ǽ١���ϸ�������Ĵ��в��������û�ĺۼ���������Ҳ
ûʲô��Ŀ���֮����
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "statue" : "�����ƺ������ǹ���������\n",
]));
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"temple-qiandian",
  "south" : __DIR__"jitan",
]));
  setup();
}
void init()
{
  add_action("do_push", "push");
}
int do_push(string arg)
{
  object me=this_player();
  int myeffstr=me->query("str")+me->query_skill("unarmed", 1)/10-2;
  int mykar=me->query_kar(), diff=40-mykar, percentage;
  int mymaxkee=me->query("max_kee"), mymaxsen=me->query("max_sen");
  if ((arg != "statue" && arg != "������") || !arg)
    return notify_fail("��Ҫ��ʲô��\n");
  if (me->is_busy()) return notify_fail("��æ���أ�\n");
  if (me->query_temp("no_move")) return notify_fail("�㱻��ס�ˣ�ʲôҲ�ɲ��ˡ�\n");
  if (me->query_skill("yaofa", 1) > 15
   && me->query("family/family_name") == "�ݿ�ɽ�޵׶�")
  {
      message_vision("$N��ָ���������������ˣ�\n", me);
      me->move(__DIR__"shanlu1");
      return 1;
  }
  if (me->query_str()<30||myeffstr<20)
    {
      message_vision("$N�������������ƶ������Ѿ���ţ����֮����Ҳ�����÷ֺ���\n", me);
      return 1;
    }
  if(random(diff)>4)
    {
      message_vision("ֻ����������һ������������һ��ש�ߣ�������$Nͷ����\n", me);
      message_vision("$N�˵����أ�������־Ҳ�е㲻���ˡ�\n", me);
      percentage=diff*2;
      me->receive_wound("kee", mymaxkee*percentage/100);
      me->receive_damage("sen", mymaxsen*percentage/100);
      return 1;
    }
  message_vision("$N�����ƶ�����ֻ��һ������������������ǰ¶��һ���󶴡�\n", me);
  message_vision("$N����һԾ�����˽�ȥ�����漴�ֺ����ˡ�\n", me);
  me->move(__DIR__"shanlu1");
  return 1;
}
