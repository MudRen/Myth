// Room: /d/4world/huofang.c
inherit ROOM;

void create ()
{
  set ("short", "�ֿ�");
  set ("long", @LONG

���ﲻ֪���Ǽ��̺ŵĲֿ⣬��Χ��������ѷ���Щ���ӡ��ֿ���
�������˺ܶ࣬����ǹ��Žŵ����꺺�ӡ�һ����һ�˵İ����Ż�
�ǽ�������Ŵ󱨣�������ȱ���֣�Ҫ����������(work)��
LONG);
  set("objects", ([ /* sizeof() == 1 */
]));

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"west1",
]));

  setup();
}
void init()
{
        add_action("do_work", "work");
}

// �ϸ����ƽ���
// �ϸ������ٶ�
// mudring.
int do_work(string arg)
{
        object ob;
        object me;

        me = this_player();

        if (me->is_busy()) {
                return notify_fail("�Աߵ�׳���Ͻ��������������Ъһ�����\n");
        }

        tell_object(me,"��ӳ���ж��һ�����Ĵ��ף�������ǽ�ߣ��۵��������ۣ�\n");
        me->add("kee",-20);
        me->add("sen",-20);
        ob = new("/obj/money/silver");
        ob->move(me);
        tell_object(me,"�Ա߹�������ͷЦ���еض���˵����������������Ĺ�Ǯ��\n");
        me->start_busy(6);
        return 1;
}
