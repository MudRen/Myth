#include <ansi.h>
inherit F_DBASE;

mapping valid_login = ([ // wiz ip
 //   "new":  ({ "127.0.0.1",}),
//  6      "stey":     ({"218.17.","219.133." }),
]);

int is_valid(string id, string ip)
{
        int i;
        if (ip == "127.0.0.1" || ip == "localhost") {
                // if (wiz_level(id)) return 1;
                return 1;
        }
/*
        if (undefinedp(valid_login[id])) {
                if (!wiz_level(id)) return 1;
                write("巫师必须有地址限制，请用 guest 登录通知天神。\n");
                destruct(this_object());
                return 0;
        }
*/
        if (undefinedp(valid_login[id])) return 1;
        else
        i = sizeof(valid_login[id]);
        while (i--) if (sscanf(ip, valid_login[id][i] + "%*s")) return 1;
        destruct(this_object());
        return 0;
}

mapping valid_multi = ([ // multi login ip
                "":             0
]);

int is_multi(string id, string ip, string port)
{
        object *usr = filter_array(objects(), (: interactive :));
        string *site = keys(valid_multi);
        int i, login_cnt = 0;

/*
        if (query(ip)) {
                write("您的地址刚有人登录，请等会再试。\n");
                return 1;
        }
*/
        set(ip, 1);
        call_out("delete", 10, ip);
        usr = filter_array(usr, (: environment :));
        i = sizeof(usr);
        while (i--) if (usr[i]->query("id") != id && query_ip_number(usr[i]) == ip) login_cnt++;
//  62          write("您的 IP 是：" HIW + ip + ":" + port + NOR "，此地址另有" + chinese_number(login_cnt)+"位玩家在线。\n");
        write("您的 IP 是：" HIW + ip + NOR "，此地址另有" + chinese_number(login_cnt)+"位玩家在线。\n");
        if (!login_cnt) return 0;
        i = sizeof(valid_multi);
        while (i--) if (sscanf(ip, site[i] + "%*s")) break;
        if (i < 0) {
                write("对不起，您目前的地址禁止多重登录，请与巫师联系。\n");
                return 1;
        }
        if (!(i = valid_multi[site[i]])) return 0;
        if (login_cnt < i) return 0;
        write("对不起，您目前的地址已到达人数限制，请与巫师联系。\n");
        return 1;
}

// this function used to seek the ip who login from
// used ip data from Wry020325
// so big eval_cost and need modify
// mudring Aug/05/2002
string seek_ip_address(string ip)
{
#if 0
        string ip_file, str, *user_ip, *ip_address;
        int i, j, k = 0, l, m, n;
        int now_ip, start_ip, end_ip;

        user_ip = explode(ip, ".");

        if (atoi(user_ip[0]) <= 61)
                ip_file = CONFIG_DIR "ipdata1";
        else if (atoi(user_ip[0]) <= 161)
                ip_file = CONFIG_DIR "ipdata2";
        else if (atoi(user_ip[0]) <= 172)
                ip_file = CONFIG_DIR "ipdata3";
        else if (atoi(user_ip[0]) <= 193)
                ip_file = CONFIG_DIR "ipdata4";
        else if (atoi(user_ip[0]) == 194
                 || (atoi(user_ip[0]) == 195 && atoi(user_ip[1]) < 60))
                ip_file = CONFIG_DIR "ipdata5";
        else if (atoi(user_ip[0]) <= 201)
                ip_file = CONFIG_DIR "ipdata6";
        else if (atoi(user_ip[0]) <= 202)
                ip_file = CONFIG_DIR "ipdata7";
        else if (atoi(user_ip[0]) <= 211)
                ip_file = CONFIG_DIR "ipdata8";
        else if (atoi(user_ip[0]) <= 217)
                ip_file = CONFIG_DIR "ipdata9";
        else
                ip_file = CONFIG_DIR "ipdata10";

        str = read_file(ip_file);
        if (! str) return "无法读取数据，请与管理员联系";
        ip_address = explode(str, "\n");
        l = sizeof(ip_address);
        for (i = 0; i < l; i++) {
                if (atoi(ip_address[i][0..2]) == atoi(user_ip[0])) {
                        for (j = 1; j < 4; j++) {
                                m = j * 3;
                                n = m + 13;

                                start_ip = atoi(ip_address[i][m..m + 2]);
                                end_ip = atoi(ip_address[i][n..n + 2]);
                                now_ip = atoi(user_ip[j]);
                                if (now_ip <= end_ip && now_ip >= start_ip)
                                        k++;
                        }
                        if (k == 3) {
                                return "来自" + ip_address[i][26..];
                        }
                        k = 0;
                }
        }
#endif
        return "未知IP来源，暂时无法确定";
}
