// Room: /d/qujing/wudidong/dong1.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������Σ���ʼ�ŵء���Ŵ�����խ�����ڳ�����ɭɭҲ�����������
ֻ�����ű������ſ��(shibei)���ʼ�ȴ��Ϊ���㡣���Ǳ���������
����Ц��������չ�͸�롣
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dong2",
  "up" : __DIR__"dong",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "shibei" : "
\t\t\t��
\t\t\t��
\t\t\tɽ
\t\t\t��
\t\t\t��
\t\t\t��
 
",
]));
  set("outdoors", 0);

  setup();
}
