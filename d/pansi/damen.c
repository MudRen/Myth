// damen.c
// by lestat//20001

inherit ROOM;

void create()
{
        set("short", "��˿��");
        set("long", @LONG
�����Ҷ���ͻȻ֮�䣬������һ���������Բ�ԭ���Ǹ��Ż����Ż�
�ĺ�������һ��ͭ�����ɵĴ��ţ�ʮ�ֳ��ء���ʹ�Ǳ����ܺõ��ˣ�����Ҳ
������Ϊ������
LONG );
	set("exits", ([
		"north" : __DIR__"shidong",
		"south" : __DIR__"yandong",
	]));
	  set("pansi", 1);

    set("objects", ([ // sizeof() == 1 
            "/obj/zhangmen/pansi.c" : 1,
]));
  set("valid_startroom", 1);
  setup();
}
