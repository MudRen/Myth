// Room: /d/jjf/side_keting.c

inherit ROOM;

void create ()
{
  set ("short", "ƫ��");
  set ("long", @LONG
ƫ�����õ���Ϊ���ţ�˿��û�������ϵ��������ա�һ�ź�ľ
���������и���񣬹�����˸�ʽ�������顣ǽ�Ϲ��ż����ֻ���
����������ʱ�������ֿ��Ե��鷿�á�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"keting",
]));

  setup();
}
