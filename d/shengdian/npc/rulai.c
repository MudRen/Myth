// cigar �ֻ�ת��NPC

#include <ansi.h>
inherit NPC;

string *fo_names = ({
    "�����ӷ�",
    "�����ٷ�",
    "��ղ�����",
    "�����",
    "��������",
    "�����Ʒ�",
    "���¹��",
    "�����޷�",
    "�����Ƿ�",
    "�����ӷ�",
    "���»���",
    "�Ź��·�",
    "���β���",
    "�̴���",
    "Ħ�ᴱ��",
    "�۾��շ�",
    "���¹�����",
    "��ȹ��",
    "��������",
    "�����׷�",
    "�����Ϸ�",
    "�𻪹��",
    "�Ź�����",
    "�ǻ�ʤ��",
    "�������",
    "���¹��",
    "��������",
    "�۴�ʤ����",
    "�𺣹��",
    "��ͨ���",
});

int query;
void create() 
{  
    set_name("��������", ({ "rulai fozu", "rulai", "fo" })); 
    set("title", "������Ӱ�٤��"); 
    set("long", "��ȴ���ɽ������ɲ������Ӱ�٤��������ү��\n"); 
    set("gender", "����"); 
    set("age", 10000); 
    set("attitude", "peaceful"); 
    set("rank_info/self", "ƶɮ"); 
    set("rank_info/respect", "����үү"); 
    // set("class", "bonze"); 
    set("str",100); 
    set("per",100); 
    set("max_kee", 10000); 
    set("max_gin", 10000); 
    set("max_sen", 10000); 
    set("force", 10000); 
    set("max_force", 10000); 
    set("force_factor", 500); 
    set("max_mana", 10000); 
    set("mana", 10000); 
    set("mana_factor", 500); 
    set("combat_exp", 4000000); 
    set("daoxing", 10000000); 
    query = 1;
   
    setup();
    carry_object("/d/obj/cloth/jia_sha")->wear(); 

}

void init()
{
    if (query = 1)
    {
        STATU_D->set_npc_skill(this_object(), 300, "�Ϻ�����ɽ");
        query = 0;
    }
    add_action("do_shouli", "baili");
}

void announce(string str) 
{ 
    command("mete " + str); 
} 

int do_shouli(string arg)
{
    int i, j, level;
    mapping skill;
    object who;
    string *skillnames;
    who = this_player();

    seteuid(getuid());
        
    if (!metep(who))
    {
        command("say �������������");
        return 1;
    }
         
    who->command("say �ݼ��������棬����ת���������ܷ���");

    level = who->query("opinion/mete");
    i = sizeof(fo_names);
    if (who->query("opinion/mete_name") == fo_names[i-level] )
    {
        command("say ���Ѿ��ܱ����ķ���");
        return 1;
    }

    if (level > i)
    {
        command("say ���Ѿ����������������꣡");
        who->set("opinion/done","�����������");
        who->set("title",HIR"�����������"NOR);
        return 1;
    }

    who->set("opinion/mete_name",fo_names[i-level]);
    who->set("shouli_where",fo_names[i-level]);

    announce("���᱾�������������̨��������һ��δ�Ⱦ������");
    announce("��������������ô�೾�̣�������������죬�����������ա�");
    announce("����һ���������㡣��������̥����ʪ����������");
    announce("����ɫ����ɫ�������������롣���������������롣���������缰����˵��");
    announce("��Ӧ��ס���ġ���Ӧ��ס�Ƿ��ġ���Ӧ������ס�ġ����Թʡ�������ס��Ϊ��ס�ʡ�");
    announce("�ֻ�ת���տյ�ȥ��������������һ�ȣ�" + who->query("name") +
        "�ƺ쳾֮�������׷���Ĺ��ҷ��ֻ�ת����");
    announce("��������" + who->name() + fo_names[i-level] + "��λ����ɽ����"
        + fo_names[i-level] + "����������");

    who->set("rank", COLOR_D->random_color(4) 
        + fo_names[i-level] + NOR);
    who->save();
              
    return 1;
}

 
void die() 
{ 
    if (environment()) 
        message("sound", "\n\n��������һ��ͷ�����ޱߣ�\n\n", environment()); 
    NPC_D->full_hp_status(this_object());
} 
 
void unconcious() 
{ 
    die (); 
}


