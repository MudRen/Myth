//Cracked by Roath

inherit ROOM;
void create ()
{
      set ("short", "Т���");
        set ("long", @LONG

    һ����������ʯ��·,ֻ��һ����ͨ�������Ե��̺���
�������������Ƕ�����Ц�ݣ������߹�����ʱ���ϰ��Ƕ���
ʧʱ�������������š�����������š�
LONG);
        set("exits",
        ([ //sizeof() == 4
                "west" : __DIR__"yamen",
                 "north": __DIR__"ngate",
                "south": __DIR__"xw-1",
      ]));
      set("objects", ([
                              __DIR__"npc/people" :1,
             ]));
    set("outdoors", "JZ");
 set("no_clean_up", 0);
        setup();
}
