inherit NPC;

void create()
{
        set_name("С����", ({ "spirit" }) );
        set("race", "����");
        set("age", 5);
        set("long", 
"һֻ����͸�������С���飬�ں��Ϻ��µط��裬����ȥ�ƺ�����ץ(catch)����\n");
        set("max_kee", 90);
        set("limbs", ({ "ͷ��", "����" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 100); 
        set_skill("spirit-dodge", 100);
        map_skill("dodge", "spirit-dodge");
        setup();
}


