
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һƬ������,�������˺��һ����Ҷ.��һ��С����Լ��������,ǰ 
���ƺ�������һ������. 
LONG
        );

        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/chen" : 1,
        ]));
        set("exits", ([ /* sizeof() == 4 */
                "west" : __DIR__"fmxh",
                "northeast" : __DIR__"shulin1",
        ]));
        set("outdoors", 1);

        setup();
}
