// Room: /d/qujing/firemount/firemount-wudidong1
inherit ROOM;

void create ()
{
  set ("short", "ȡ��·");
  set ("long", @LONG

�뿪�˱����������̤��������֮·����ǰ��һƬһ���޼ʵ�ƽҰ��
��Ұ�ڲ���һ�����̡��ֲ�֪Ҫ�ȹ����ٸ����˰������;֮ҹ����
��֪Ҫ������Զ��ٶ���Ұ�ޣ���ħ����ˡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"firemount-wudidong2",
  "southeast" : "/d/qujing/biqiu/lin3",
]));
  set("outdoors", "/d/qujing/wudidong");

  setup();
}
