// fly.c

inherit NPC;

void create()
{
        set_name("��Ӭ", ({ "fly" }));
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 1);
        set("long", "һֻ��ͷ��Ӭ��ר���ڷ�����ת��\n");
        
        set("str", 30);
        set("dex", 30);

        set("limbs", ({ "ͷ��", "���", "ǰ��", "���"}) );
        set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 6);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "��Ӭ��ͣ������ߴ�ת��������������\n",
                "��Ӭͣ��һ�ѷ���ϣ�̰����˱���š�\n",
                "��ӬͻȻһ�����壬�������ıǿף��ַ��˳�����\n",
                "��Ӭ���������ͣ��������ϣ��������ġ�\n",
                "��Ӭ����һ�������񣬷ɵ������е������������\n",
                "��Ӭ��С�ĵ�������Ŀ������������¶ǣ�������Ż��һ�ض��ǡ�\n"}));
        set_temp("apply/attack", 10);
        set_temp("apply/parry", 10);
        setup();
}


