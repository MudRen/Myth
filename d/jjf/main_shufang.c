// Room: /d/jjf/main_shufang.c

inherit ROOM;

void create ()
{
  set ("short", "̾��ի");
  set ("long", @LONG
��̫�����������׷��ؽ���һ�ԼҴ�ﵣ���׼������ϵ������
��Խ�װﵿ����ϴ������´����������������ﵹ���̫�ڵ�
����ǰ��ȼ��ף��������֮�⣬���в�������������Խ���Ե�ׯ�ϡ�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"main_cabinet",
]));

  setup();
}
