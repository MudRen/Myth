// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
һ̶��ˮ��ͣ��ð�����ݣ���֦��Ҷ��ͬ���Ƶİ׹����гߺ�
���鰵��ɫ��������ʯ���ں�ˮ���룬���沼���˸���ʬ����̶ˮ
��Ư���Ŷζο�ľ����Щ��ɢ�����������̡�
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"zhaoze4",
]));
        set("objects", ([
                __DIR__"npc/dragon" : 1,
       ]) );
        set("no_magic",1);
        set("no_spells",1);
        setup();
        replace_program(ROOM);
}
