//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// jiading.c

inherit NPC;

void create()
{
       set_name("��ĸ", ({"liu mama","mama"}));
       set("long","һ���������̫̫��\n");
       set("gender", "Ů��");
       set("age", 66);
       set("str",40);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("combat_exp", 1800);
       set_skill("stick", 15);
       set_skill("parry", 25);
       set_skill("dodge", 35);
       set("force_factor", 3);
        set("chat_chance",50);
        set("chat_msg", ({
        "��ĸ̾Ϣ������ѽ�����ȥ�Ҹ�����ĺ���Ϊ�㸸�׳��Ȱ���\n",
        "��ĸ�૵�����������ް����ӷ�\n",
        }));
        setup();
        add_money("coin", 50);
 	carry_object("/d/qujing/shuangcha/obj/cloth")->wear();
 	carry_object("/d/qujing/shuangcha/obj/fozhu")->wear();

}

