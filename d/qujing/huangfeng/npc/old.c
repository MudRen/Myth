//Cracked by Roath

inherit NPC;

void create()
{
       set_name("����", ({"lao zhe","old man"}));
       set("long","һ����ͷ�׷������ߡ�\n");
       set("gender", "����");
       set("age", 66);
       set("combat_exp", 1800);
       set("daoxing", 1800);
        set("chat_chance",60);
        set("chat_msg", ({
        "����̾Ϣ����������ȡ���Ѱ���Ҫȡ�����õ�����ȥ�ɡ�\n",
        "�����૵�˵������ǰ�������ְ�����\n",
        }));
        setup();
        add_money("coin", 50);
        carry_object("/d/gao/obj/bang")->wield();

}

