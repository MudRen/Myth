// Room: /d/jjf/jjf_bingqi.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

������һ��������(rack)��ʮ�˰����������ȫ�������Ա߹�����ʮ
����������Ŀ��ף���������սѥ����Ա�һλ��������Ŀ����
�������Ը���Ҫһ���¼׺�һ�����ֵı�����
LONG);

  set("outdoors", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qinping" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"front_yard2",
]));

  set("item_desc", ([
"rack": "
�������ϲ��ţ�

����(sword)������(blade)��ͭ�(mace)����ǹ(spear)��
����(hammer)���師(axe)���ֲ�(fork)��������(stick)��

�Ա߰��ţ�

ذ��(dagger)��Ƥ��(whip)������(bow)����һЩ�ɻ�ʯ(throwing)��

һ���¼��Ϲ��ţ�

�ֿ�(head)������(body)�����ľ�(waist)����սѥ(feet)��

",
]));
  setup();
}
