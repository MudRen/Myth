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
                "west" : __DIR__"huadian",
                "east" : __DIR__"baozi",
                "north": __DIR__"xw-2",
                "south": __DIR__"center",
      ]));
      set("objects", ([
                              __DIR__"npc/people" :1,
             ]));
    set("outdoors", "JZ");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
  }
