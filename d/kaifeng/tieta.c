//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "�꾩����");
  set ("long", @LONG

�㳡���м�������һ���߸ߵĺ�ɫ�����������������Ǻ�ɫò������
���͡���˵һλ����������ȡ������֮���꾩�����ᵽ�˴�������
�����ǳ����������Ϸ������������������������߷ֱ�ͨ����������
�Ĵ�֡�

LONG);

  set("exits", ([
        "west" : __DIR__"chen2",
        "east" : "/d/southern/wutai/guandao3",
        "southeast" : __DIR__"yuwang1",
        "northeast" : __DIR__"yao5",
        "northwest" : __DIR__"shun5",
      ]));

  set("outdoors", __DIR__);
           set("post_limit", 1);

  setup();
          call_other("/obj/board/kaifeng_b", "???");

}


