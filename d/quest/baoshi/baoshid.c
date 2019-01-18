// File：/quest/baoshi.c 
// Changed to heart_beat() by mudring@sjsh...... 
 
#include <ansi.h> 
 
inherit F_DBASE; 
int random_place(string dirss,object bs); 
 
string *dirs = ({ 
"/d/changan", 
"/d/city", 
"/d/eastway", 
"/d/gao", 
"/d/lingtai", 
"/d/moon", 
"/d/nanhai", 
"/d/sea", 
"/d/westway", 
"/d/qujing/wuzhuang", 
"/d/ourhome/honglou", 
"/d/death", 
"/d/penglai", 
"/d/xueshan", 
"/d/qujing/baotou", 
"/d/qujing/baoxiang", 
"/d/qujing/bibotan", 
"/d/qujing/biqiu", 
"/d/qujing/chechi", 
"/d/qujing/dudi", 
"/d/qujing/fengxian", 
"/d/qujing/firemount", 
"/d/qujing/jilei", 
"/d/qujing/jindou", 
"/d/qujing/jingjiling", 
"/d/qujing/jinping", 
"/d/qujing/jisaiguo", 
"/d/qujing/maoying", 
"/d/qujing/nuerguo", 
"/d/qujing/pansi", 
"/d/qujing/pingding", 
"/d/qujing/qilin", 
"/d/qujing/qinfa", 
"/d/qujing/qinglong", 
"/d/qujing/tianzhu", 
"/d/qujing/tongtian", 
"/d/qujing/wudidong", 
"/d/qujing/wuji", 
"/d/qujing/xiaoxitian", 
"/d/qujing/yinwu", 
"/d/qujing/yuhua", 
"/d/qujing/zhujie", 
"/d/qujing/zhuzi", 
}); 
 
string *dirname = ({ 
"长安城", 
"长安城内", 
"长安城东", 
"高老庄", 
"灵台方寸山", 
"月宫", 
"南海普陀山", 
"东海龙宫", 
"长安城西", 
"五庄观", 
"红楼一梦", 
"阎罗地府", 
"蓬莱仙岛", 
"大雪山", 
"豹头山", 
"宝象国", 
"碧波潭", 
"比丘国", 
"车迟国", 
"毒敌山", 
"风仙郡", 
"火焰山", 
"积雷山", 
"金兜山", 
"荆棘岭", 
"金平府", 
"祭赛国", 
"毛颖山", 
"女儿国", 
"盘丝岭", 
"平顶山", 
"麒麟山", 
"钦法国", 
"青龙山", 
"天竺国", 
"通天河", 
"无底洞", 
"乌鸡国", 
"小西天", 
"隐雾山", 
"玉华县", 
"竹节山", 
"朱紫国", 
}); 
 
void create() 
{ 
        seteuid(getuid()); 
        set("channel_id", "宝石精灵"); 
} 
 
void choose_baoshi() 
{ 
        int i, j ,k,ppl,rd; 
        object *list,newob; 
        string str,m_name; 
        string smp; 
         
        j = random(sizeof(dirs)); 
        rd = random(6);  
      
          
                newob = new(__DIR__"baoshi");
                 str = "神"; 
        
        reset_eval_cost(); 
                 
        if(random_place(dirs[j],newob)== 1 )
        message_job( HIR"奇珍异宝："+HIW"突然空中打了个炸雷,一个火球横空出世,拖着一道"+str+"光向"+dirname[j]+"的方向落去！"); 
        if(newob->query("b_lvl")>14)
        message_job( HIR"奇珍异宝："+newob->name()+"降临凡间！"); 
        return ; 
} 
 
int random_place(string dirss,object bs) 
{ 
        int  j, k; 
        object  newob,ob; 
        mixed*  file, exit; 
        string id_name; 
        file = get_dir( dirss+"/npc/*.c", -1 ); 
         
        if( !sizeof(file) ) return 0; 
 
        for(k=0;k<50;k++) { // try 50 times 
           j = random(sizeof(file)); 
           if( file[j][1] > 0 ) { 
             newob=load_object(dirss+"/npc/"+file[j][0]); 
             if(!newob) continue; 
             id_name = newob->query("id"); 
             destruct(newob); 
             if(!id_name) continue; 
             if(!objectp(ob=find_living(id_name))) continue; //这个npc不是活的  
                     if(bs->move(ob)) { 
                    CHANNEL_D->do_channel( this_object(), "sys", "宝石落到了"+ob->query("name")+"("+ob->query("id")+")的身上。");  
                     return 1; 
                    } 
             } 
           } 
         CHANNEL_D->do_channel( this_object(), "sys", "本次宝石发布失败"); 
        return 0; 
} 

