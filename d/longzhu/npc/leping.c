// ��ƽ by Calvin

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("��ƽ", ({"le ping","ping","le"}));
        set("title", HIG"������Ѳʹ"NOR);
        set("long", "һλ�����µ�Сѧͽ��\n");

        set("gender", "����");
        set("color", HIW);
        set("attitude", "peaceful");

        set("age", 19+random(1));
        set("combat_exp", 5000000+random(5000000));
        set("daoxing", 5000000+random(5000000));

        set("shen_type", 1);
        set("per", 25);
        set("max_kee",100000);
        set("max_gin", 100000);
        set("force", 1000);
        set("spells", 1000);
        set("force_factor", 10);
        set_skill("force", 100+random(100));
        set_skill("unarmed",500+random(500));
        set_skill("dodge",500+random(500));
        set_skill("parry", 500+random(500));

        setup();
        carry_object("/d/quest/longzhu/armor/xingtian")->wear();
        carry_object("/d/quest/longzhu/obj/5");
        setup();
}

void die()
{
 int i;
 object me,*inv;
 if(objectp(me=query_temp("last_damage_from") ))
        {
            inv = all_inventory(this_object());
            for(i=0; i<sizeof(inv); i++)
            {
                if (inv[i]->query("id")=="5" || inv[i]->query("id")=="huang longzhu")
                {
                   inv[i]->move(me);
                   message_vision("$N����һö����ɫ�����ӣ�$n��æһ��ץ�����\n",this_object(),me);
            message("channel:rumor",HIG+"��"HIW"���鴫˵"HIG"��"HIC"�����"HIW"����˵"+me->query("name")+"�ڳ����Ǹ����õ���"HIY"������"HIW"��\n"+NOR,users());
         }
        }
  }
 ::die();
}

int accept_fight(object me)
{
        command("say �ðɣ����꼼�գ��㵽Ϊֹ,�����Ӯ���Ҿ͸�����������£�\n");
        command("say ��ֻ֪���������,������һ�Ų�֪��\n");
        command("say �Ҹ������������,��ɲ�Ҫ˵����˵�İ���\n");
        command("say �����ǵ��Ǹ�����������η�ɮ���ǵ����п�,��֪�����Ǽ٣�\n");
        command("say �����������ʲôҲ��֪���ˣ�\n");
        return 1;
}
int accept_ask(object me)
{
        command("say ��ֻ֪���������,������һ�Ų�֪��\n");
        command("say �Ҹ�����һ������,��ɲ�Ҫ˵����˵�İ���\n");
        command("say �����ǵ��Ǹ�����������η�ɮ���ǵ����п�,��֪�����Ǽ٣�\n");
        command("say �����������ʲôҲ��֪���ˣ�\n");
        return 1;
}



