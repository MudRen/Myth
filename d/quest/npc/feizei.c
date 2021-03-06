// Fild：/d/npc/feizei.c
// Changed to heart_beat() by mudring@sjsh......

#include <ansi.h>

inherit F_DBASE;

string *families = ({
  "大雪山",
  "方寸山三星洞",
  "月宫",
  "南海普陀山",
  "阎罗地府",
  "盘丝洞",
  "将军府",
  "东海龙宫",
  "陷空山无底洞",
  "五庄观",
  "火云洞",
  "蜀山剑派",
  "大唐皇宫",
  "乌鸡国",
  "宝象国",
  "天竺国",
  "女儿国",
  "玉华县",
});

string *feizei=({"fei-putuo","fei-moon","fei-wzg","fei-shushan","fei-hyd",
    "fei-fangcun","fei-hell","fei-jjf","fei-pansi","fei-dragon", "fei-xueshan",
     "fei-wudidong",});

void create()
{
        seteuid(getuid());
        set("channel_id","");
}

void choose_npc()
{
        int i, j ,k,ppl;
        object *list, newob;
        string str,m_name;
        string smp;
        smp  = "本门镇山之宝";
                   
        j = random(sizeof(families));
        k = random(sizeof(families));
        newob = new(__DIR__+feizei[random(sizeof(feizei))]);
        newob->set("target",families[k]);
        newob->invocation( j );
        reset_eval_cost();
        
        switch(families[k])
        {
                case "方寸山三星洞":
                        m_name="菩提老祖";//
                        newob->carry_object("/d/npc/obj/stick");
                        break;
                case "月宫":
                        m_name="西王母";//
                        newob->carry_object("/d/npc/obj/whip");
                        break;
                case "阎罗地府":
                        m_name="地藏王菩萨";//
                        newob->carry_object("/d/npc/obj/whip");
                        break;
                case "陷空山无底洞":
                        m_name="玉鼠精";//
                        newob->carry_object("/d/npc/obj/blade");
                        break;
                case "将军府":
                        m_name="白发老人)";//
                        newob->carry_object("/d/npc/obj/axe");
                           break;
                case "火云洞":
                        m_name="黄飞虎";//
                        newob->carry_object("/d/npc/obj/spear");
                        break;
                case "大雪山":
                        m_name="大鹏明王";//
                        newob->carry_object("/d/npc/obj/qin");
                        break;
                case "五庄观":
                        m_name="镇元大仙";
                        if(random(2)) 
                           newob->carry_object("/d/npc/obj/staff");
                        else
                           newob->carry_object("/d/obj/drug/renshen-guo");
                        break;
                case "南海普陀山":
                        m_name="观音菩萨";//
                        newob->carry_object("/d/npc/obj/staff");
                        break;
                case "东海龙宫":
                        m_name="敖广";//
                        newob->carry_object("/d/npc/obj/fork");
                        break;
                case "盘丝洞":
                        m_name="紫霞仙子";//
                        newob->carry_object("/d/npc/obj/whip");
                        break;
                case "蜀山剑派":
                        m_name="蜀山剑圣";//
                        newob->carry_object("/d/npc/obj/sword");
                        break;
                case "大唐皇宫":
                        m_name="唐太宗";//
                        newob->carry_object("/d/npc/obj/mace");
                        smp = "大唐国宝";
                        break;
                case  "乌鸡国":
                        m_name="乌鸡国国王";//
                        newob->carry_object("/d/npc/obj/kui");
                        smp = "乌鸡国国宝";
                        break;
                case  "宝象国":
                        m_name="宝象国国王";//
                        newob->carry_object("/d/npc/obj/magua");
                        smp = "宝象国国宝";
                        break;
                case  "天竺国":
                        m_name="天竺国国王";//
                        newob->carry_object("/d/npc/obj/pifeng");
                        smp = "天竺国国宝";
                        break;
                case  "女儿国":
                        m_name="女儿国国王";//
                        newob->carry_object("/d/npc/obj/ring");
                        smp = "女儿国国宝";
                        break;
                case  "玉华县":
                        m_name="玉华县县令";//
                        newob->carry_object("/d/npc/obj/shoes");
                        smp = "玉华县国宝";
                        break;
                        
        }
          message_job( HIR+"江湖追杀令："+HIW+m_name+HIG"：现有蒙面飞贼盗走"+smp+"，现已逃窜至"+families[j]+"一带,杀无赦。");
}

