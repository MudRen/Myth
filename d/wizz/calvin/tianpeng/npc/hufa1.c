//�󻤷�
//by Calvin and Leox ��ͬ����
//��Ȩ����,δ�����!���÷�¼

inherit NPC;
#include <ansi.h>

void create()
{
          set_name("����", ({"lu fei","fei","hufa","lu"}));
        set("title", "����Ԫ˧���󻤷�");
          set("long","��������Ԫ˧����һ����ɫ�ĺ�����\n");
        set("class", "tianpeng");
        create_family("����Ԫ˧��", 3, "����");
          set("gender", "����");
          set("age", 50);
          set("per",30);        
          set("combat_exp", 1000000);
          set("daoxing",1000000);
          set("per", 30);
          set("str", 30);
          set("max_kee", 2000);
          set("kee",2000);
          set("force_factor",80);
          set("max_sen", 1000);
          set("sen",1000);
          set("force", 1000);
          set("max_force", 1500);
          set("max_mana", 1500);
          set("mana", 1000);
          set_skill("unarmed", 100);
          set_skill("dodge", 100);
          set_skill("force", 100);
          set_skill("parry", 100);
          set_skill("staff", 220);
          set_skill("spells", 100);
//          map_skill("spells", "buddhism");

         setup();
        carry_object("/d/qujing/liusha/obj/staff")->wield();
}

void attempt_apprentice(object ob)
{
        if( (string)ob->query("family/family_name")=="����Ԫ˧��" ){
                if( (int)ob->query("family/generation") < 2  ){
                        command("say һ��ȥ����Ц��!�Ҹð�" + RANK_D->query_respect(ob) + "��Ϊʦ���ǡ�\n");
                }
                else if( (int)ob->query("family/generation") ==2  ){
                        command("say �����" + RANK_D->query_rude(ob) + "������ǲ��С���ˣ�\n");
                }
                else if( (int)ob->query("family/generation") ==3  ){
                        command("blush ");
                        command("say �����" + RANK_D->query_rude(ob) + "���Ǻð�,����Ҫ֪�����֮��֮...\n");
                        command("recruit " + ob->query("id") );
                }
                else {
                        if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 500000 ){
                                command(":) ");
                                command("say �ã�" + RANK_D->query_respect(ob) + "��Ȼ�������¾͵ø����������ɲ���͵����\n");
                                command("recruit " + ob->query("id") );
                        }
                        else {
                                command("say �㻹�����������������Űɡ�\n");
                        }
                }
        }

        else{
                command("hmm");
                command("say ��λ" + RANK_D->query_respect(ob) + "���㻹�������������������ɡ�\n");
        }

        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "tianpeng");
}
