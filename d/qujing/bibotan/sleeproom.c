inherit ROOM;

void create()
{
        set("short", "˯��");
        set("long", @LONG

�����Ǳ̲�̶���ӵ�˯�������������ż���С����
���ں�����˯��
LONG
        );
        set("light_up", 1);
        set("sleep_room", 1);
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"longtai2",
]));
        set("no_magic", 1);

        setup();
        replace_program(ROOM);
}
