//Cracked by Roath

#include <dbase.h>

inherit  NPC_SAVE;

void greeting(object me);

//string query_save_file() { return "/data/npc/leitaiscore";}

void create()
{
    reload("leitaiscore");
        set_name("����", ({"chang jian","bookkeeper","jian"}));
        set("long","һ���������ݵ��佫��ר�Ÿ���ά�ֻ᳡����\n");

        set("gender", "����");
        set("age", 44);
        set("per",30);
        set("kee", 800); 
        set("max_kee", 800);
        set("sen", 200);
        set("max_sen", 200);
        set("combat_exp", 50000);
        set("attitude", "friendly");
        setup();
        carry_object("/d/obj/armor/jinjia")->wear();
}
