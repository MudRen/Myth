
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һƬ������,�������˺��һ����Ҷ.��һ��С����Լ��������,ǰ
���ƺ�������һ������.
LONG
        );

        set("exits", ([ /* sizeof() == 3 */
                "east" : "/d/gao/daotian2",
                "southwest" : __DIR__"shulin2",
        ]));
        set("outdoors", 1);

        setup();
}

