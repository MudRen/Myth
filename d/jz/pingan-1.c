//Cracked by Roath
inherit ROOM;
void create()
{
  set ("short", "�ж���");
  set ("long", @LONG

        ���С��Ҳ����һ����ʷ�ˣ�����λ��ƫԶ�������ؾ���Ҳ
���Ǻܶ࣬�����ճ���С�ǵ�ĩ�䡣����ȻԶ�Ȳ��˳����ķ�������
��ȴ�������񾲵ķ�Χ��

LONG);
        set("exits", ([
  "east" : __DIR__"center",
  "west" : __DIR__"chengen-2",
  "south": __DIR__"zhahuopu",
  "north": __DIR__"zhongyao",
]));
  setup();
}
