inherit ROOM;

void create()
{
  set ("short", "ũ��");
  set ("long", @LONG

һ�����ũ�ᣬ��ɨ�ĸɸɾ������������������ȵ���λ������
���м�����������ˮ����ǽ�Ƕ��Ÿ��ֹϹ��߲ˣ�����ֱ����ˮ��
LONG);

set("exits", ([ /* sizeof() == 4 */
"west" : __DIR__"cunkou",
]));

set("objects", ([
            "/d/ourhome/obj/xbc" : 1,
            "/d/ourhome/obj/beans" : 1,
            "/d/ourhome/obj/carrot" : 1,
]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

